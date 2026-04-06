#pragma once

#include "include/domain/game_limits.h"
#include <stdbool.h>
#include <stdint.h>

typedef struct {
  uint32_t created_ts;
  uint8_t player_count;
  uint8_t impostor_count;
  uint16_t word_index;
  char title[IMPOSTOR_MAX_SESSION_TITLE_LEN];
  char names[IMPOSTOR_MAX_PLAYERS][IMPOSTOR_MAX_NAME_LEN];
} SavedGameRecord;

bool saved_games_load(SavedGameRecord *out, uint8_t *count_out);

bool saved_games_append(const SavedGameRecord *record);

bool saved_games_replace_at(uint8_t index, const SavedGameRecord *record);

bool saved_games_delete_at(uint8_t index);
