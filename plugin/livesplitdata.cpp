#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#define DLL_USE
#include <adll.h>
#include "livesplitdata.h"

static LiveSplitData liveSplitData;

BOOL APIENTRY DllMain(
    HANDLE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
) {
    engine_bind();
    return TRUE;
}

DLLFUNC void SetGameStarted(char value) {
    liveSplitData.isGameStarted = value;
}

DLLFUNC char GetGameStarted() {
    return liveSplitData.isGameStarted;
}

DLLFUNC void SetGameComplete(char value) {
    liveSplitData.isGameComplete = value;
}

DLLFUNC char GetGameComplete() {
    return liveSplitData.isGameComplete;
}

DLLFUNC void SetLoading(char value) {
    liveSplitData.isLoading = value;
}

DLLFUNC char GetLoading() {
    return liveSplitData.isLoading;
}

DLLFUNC void SetParadoxTrianglesCollected(int value) {
    liveSplitData.paradoxTrianglesCollected = value;
}

DLLFUNC void IncrementParadoxTrianglesCollected() {
    liveSplitData.paradoxTrianglesCollected++;
}

DLLFUNC int GetParadoxTrianglesCollected() {
    return liveSplitData.paradoxTrianglesCollected;
}

DLLFUNC void SetKeysCollected(int value) {
    liveSplitData.keysCollected = value;
}

DLLFUNC void IncrementKeysCollected() {
    liveSplitData.keysCollected++;
}

DLLFUNC int GetKeysCollected() {
    return liveSplitData.keysCollected;
}

DLLFUNC void SetBossesDefeated(int value) {
    liveSplitData.bossesDefeated = value;
}

DLLFUNC void IncrementBossesDefeated() {
    liveSplitData.bossesDefeated++;
}

DLLFUNC int GetBossesDefeated() {
    return liveSplitData.bossesDefeated;
}
