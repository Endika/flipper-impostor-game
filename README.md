# Impostor Game (Flipper Zero)

Party game helper inspired by **Undercover** / **Spyfall** style play: everyone except the impostors sees the same secret word; impostors see the same hint about that word. Roles and reveal order are randomized each session.

## Features

- **English** UI by default, **Spanish** second locale (stored on SD).
- **Main menu**: Play (saved games + create new), New game (wizard), Settings (language + credits).
- **Wizard**: Enter at least three player names, optionally add more (up to **64**), then pick impostor count. Valid range: **1 … players−2** (at least two crew). The menu highlights a **~25%** suggested default (`*`); you can still pick **1** or any other valid number.
- **Play flow**: READY → pass device → **hold OK** to reveal role → **short OK** to continue → when everyone has seen roles, **START** screen with random first speaker.
- **Word bank**: ~40 bilingual pairs in flash; one word index per game session.

## Architecture

See `docs/ARCHITECTURE.md` for layers, domain rules, and testing.

## Build

- **Host tests**: `make test` (GCC, no Flipper SDK).
- **FAP**: Point `FLIPPER_FIRMWARE_PATH` at your firmware checkout, then `make prepare` and `make fap`.

## Requirements

- [flipperzero-firmware](https://github.com/flipperdevices/flipperzero-firmware) and `./fbt` for device builds.
