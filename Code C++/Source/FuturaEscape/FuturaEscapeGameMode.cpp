// Copyright Epic Games, Inc. All Rights Reserved.

#include "FuturaEscapeGameMode.h"
#include "FuturaEscapeHUD.h"
#include "FuturaEscapeCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFuturaEscapeGameMode::AFuturaEscapeGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AFuturaEscapeHUD::StaticClass();
}
