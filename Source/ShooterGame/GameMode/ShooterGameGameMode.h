// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "ShooterGameGameMode.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERGAME_API AShooterGameGameMode : public AGameMode
{
	GENERATED_BODY()
public:
	virtual void PlayerEliminated(class AShooterCharacter* ElimmedCharacter, class AShooterPlayerController* VictimController, AShooterPlayerController* AttackerController);
	
};
