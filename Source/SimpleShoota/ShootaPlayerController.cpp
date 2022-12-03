// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootaPlayerController.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"


void AShootaPlayerController::BeginPlay() {
	Super::BeginPlay();
	
	HUD = CreateWidget(this, HUDClass);
	if (HUD != nullptr)
	{
		HUD->AddToViewport();
	}
	
}

void AShootaPlayerController::GameHasEnded(class AActor *EndGameFocus, bool bIsWinner) {
	
	Super::GameHasEnded(EndGameFocus, bIsWinner);

	HUD->RemoveFromViewport();

	if (bIsWinner)
	{
		UUserWidget* WinScreen = CreateWidget(this, WinScreenClass);
		if (WinScreen != nullptr)
		{
			WinScreen->AddToViewport();
		}
	}
	else {
		UUserWidget* LoseScreen = CreateWidget(this, LoseScreenClass);
		if (LoseScreen != nullptr)
		{
			LoseScreen->AddToViewport();
		}
	}

	GetWorldTimerManager().SetTimer(RestartHandle, this, &APlayerController::RestartLevel, RestartDelay);
}