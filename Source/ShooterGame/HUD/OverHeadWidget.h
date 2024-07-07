// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "OverheadWidget.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERGAME_API UOverheadWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* NetworkRoleText;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* PlayerNameText;
	
	void SetNetworkRoleText(FString TextToDisplay);

	UFUNCTION(BlueprintCallable)
	void ShowPlayerNetRole(APawn* InPawn);

	void SetPlayerNameText(FString PlayerName);

	UFUNCTION(BlueprintCallable)
	void ShowPlayerName(APawn* InPawn);

protected:
	virtual void NativeDestruct() override;
};
