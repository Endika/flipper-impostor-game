# Architecture

## Overview

This app is a **word-undercover** party helper: one shared secret word for everyone who is not an impostor, one shared hint for impostors, and random role assignment per session. It is structured in layers so domain logic stays testable on the host without the Flipper SDK.

## Layers

### Domain (`include/domain/`, `src/domain/`)

- **Game limits**: `IMPOSTOR_MAX_PLAYERS` (64), `IMPOSTOR_MIN_PLAYERS`, name length, and saved-game cap.
- **Rules** (`game_rules.c`): Validates player count and impostor count. Hard rule: `1 <= impostors <= player_count - 2` so at least two non-impostors share the secret word. **Suggested** impostor count is about **25%** of players (integer math), clamped to `[1, max]`. The UI preselects that value; any value from 1 to the max remains selectable (e.g. 1 impostor in a large group if you want).
- **Session** (`session.c`): Builds a game session from `GameSetup`: random impostor assignment, random reveal order, and random first speaker after all reveals.
- **Word bank** (`word_bank.c`): Read-only ROM table of English–Spanish word pairs. One row per index; `word_index` selects the same semantic pair in both languages.

No Flipper headers in domain code; only standard C.

### Infrastructure (`include/infrastructure/`)

- **Settings**: Single small file on SD card for UI locale.
- **Saved games**: Compact binary list of past setups (names, counts, last word index). Word index is re-rolled when loading a saved setup so each play gets a fresh word.

### Platform (`include/platform/`)

- **Random**: `impostor_rng_u32` wraps `furi_hal_random_get()` for device builds.

### Presentation (`src/ui/`, `src/app/`)

- **pass_view** / **card_view**: Minimal views with lock-free models; long OK on pass, short OK on card.
- **impostor_app**: View dispatcher, submenus, text input, widgets, and navigation stack.

### Internationalization (`src/i18n/`)

All user-visible strings are keyed by `ImpostorStrId`. English is the default; Spanish is a second table. Strings are stored as pointers to string literals in flash.

## Memory and storage

- Player names: `IMPOSTOR_MAX_NAMES_LEN` × `IMPOSTOR_MAX_PLAYERS` in RAM during a session.
- Word bank: pointers only; no per-word copy at runtime.
- Saved games: fixed-size records in a single file; capped at `IMPOSTOR_MAX_SAVED_GAMES`.

## Testing

Host tests (`make test`) compile domain and i18n without Flipper:

- `test_game_rules`: Rule boundaries.
- `test_session`: Deterministic RNG; impostor count; reveal order completes; starter index in range.
- `test_strings`: Locale switching and fallback.

## Build

- Host: `make test`
- Device: `make fap` with `FLIPPER_FIRMWARE_PATH` pointing at a local firmware tree and `make prepare` for the `applications_user` symlink.
