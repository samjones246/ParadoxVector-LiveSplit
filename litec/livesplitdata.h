#ifndef LIVESPLITDATA_H
#define LIVESPLITDATA_H

#define PRAGMA_BIND "livesplitdata.dll";

/**
 * Sets isGameStarted, the value representing whether or not the player has started the game.
 * Default value is 0. Should be set to 1 the moment the player clicks New Game on the main menu, or 
 * upon clicking Next on the warning dialog if it is shown. Should be set back to 0 once the first 
 * level is loaded.
 */
void SetGameStarted(char value);

/**
 * Returns the current value of isGameStarted.
 */
char GetGameStarted();

/**
 * Sets isGameComplete, the value reprenting whether or not the player has reached the end of the game.
 * Default value is 0. Should be set to the moment the player clicks Next on the final dialog box. Should be 
 * set back to 0 on returning to the main menu.
 */
void SetGameComplete(char value);

/**
 * Returns the current value of isGameComplete.
 */
char GetGameComplete();

/**
 * Sets isLoading, the value indicating if the game is currently loading a level.
 * Default value is 0. Should be set to 1 immediately before any call to load_level. Should be set back to 0 
 * immediately after any call to load_level. 
 */
void SetLoading(char value);

/**
 * Returns the current value of isLoading.
 */
char GetLoading();

/**
 * Sets paradoxTrianglesCollected, the value representing how many paradox triangles the player has collected.
 * Default value is 0.
 */
void SetParadoxTrianglesCollected(int value);

/**
 * Increments paradoxTrianglesCollected by 1.
 * Should be called when the player collects a paradox triangle.
 */
void IncrementParadoxTrianglesCollected();

/**
 * Returns the current value of paradoxTrianglesCollected.
 */
int GetParadoxTrianglesCollected();

/**
 * Sets keysCollected, the value representing how many keys the player has collected.
 * Default value is 0.
 */
void SetKeysCollected(int value);

/**
 * Increments the value of keysCollected by 1.
 * Should be called when the player collects a key.
 */
void IncrementKeysCollected();

/**
 * Returns the current value of keysCollected.
 */
int GetKeysCollected();

/**
 * Sets bossesDefeated, the value represenitng how many bosses the player has defeated.
 * Default value is 0.
 */
void SetBossesDefeated(int value);

/**
 * Increments the value of bossesDefeated by 1.
 * Should be called when the player defeats a boss, after clearing any dialog which is displayed.
 */
void IncrementBossesDefeated();

/**
 * Returns the current value of bossesDefeated.
 */
int GetBossesDefeated();

#endif