// Fill out your copyright notice in the Description page of Project Settings.


#include "OverheadWidget.h"
#include "Components/TextBlock.h"
#include "GameFramework/PlayerState.h"

void UOverheadWidget::SetNetworkRoleText(FString TextToDisplay)
{
	if (NetworkRoleText)
	{
		NetworkRoleText->SetText(FText::FromString(TextToDisplay));
	}
}

void UOverheadWidget::ShowPlayerNetRole(APawn* InPawn)
{
	ENetRole RemoteRole = InPawn->GetRemoteRole();
	FString Role;

	switch (RemoteRole)
	{
	case ENetRole::ROLE_Authority:
		Role = FString("Authority");
		break;
	case ENetRole::ROLE_AutonomousProxy:
		Role = FString("AutonomousProxy");
		break;
	case ENetRole::ROLE_SimulatedProxy:
		Role = FString("SimulatedProxy");
		break;
	case ENetRole::ROLE_None:
		Role = FString("None");
		break;
	}
	FString RemoteRoleString = FString::Printf(TEXT("Remote Role: %s"), *Role);
	SetNetworkRoleText(RemoteRoleString);
}

void UOverheadWidget::SetPlayerNameText(FString PlayerName)
{
	if (PlayerNameText)
	{
		PlayerNameText->SetText(FText::FromString(PlayerName));
	}
}

void UOverheadWidget::ShowPlayerName(APawn* InPawn)
{
	APlayerState* PlayerState = InPawn->GetPlayerState();
	FString Name;

	if (PlayerState)
	{
		Name = PlayerState->GetPlayerName();
		SetPlayerNameText(Name);
	}
}

void UOverheadWidget::NativeDestruct()
{
	RemoveFromParent();
	Super::NativeDestruct();
}

