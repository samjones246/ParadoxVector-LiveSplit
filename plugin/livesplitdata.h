#pragma once
struct LiveSplitData
{
	int IDENT = 33331524; // Allows easily locating the struct in memory.
	bool isGameStarted = false;
	bool isGameComplete = false;
	bool isLoading = false;
	int paradoxTrianglesCollected = 0;
	int keysCollected = 0;
	int bossesDefeated = 0;
};
