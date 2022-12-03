// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAIController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "ShooterCharacter.h"

void AShooterAIController::BeginPlay() {
	Super::BeginPlay();
	
	if (AIBehavior != nullptr) {
		RunBehaviorTree(AIBehavior);
		GetBlackboardComponent()->SetValueAsVector(TEXT("SpawnLocation"), GetPawn()->GetActorLocation());
		APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	}
}

void AShooterAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

}

bool AShooterAIController::bIsDead() const {
	AShooterCharacter* ControlledCharacter = Cast<AShooterCharacter>(GetPawn());
	if (ControlledCharacter != nullptr) {
		return ControlledCharacter->bIsDead();
	}

	return true;
}