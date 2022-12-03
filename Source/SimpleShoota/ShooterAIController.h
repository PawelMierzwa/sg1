// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "ShooterAIController.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLESHOOTA_API AShooterAIController : public AAIController
{
	GENERATED_BODY()

public:
	bool bIsDead() const;
	
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere)
		float AcceptanceRadius = 200;
	UPROPERTY(EditDefaultsOnly)
	class UBehaviorTree* AIBehavior;
};
