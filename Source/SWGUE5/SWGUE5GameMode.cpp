// Copyright Epic Games, Inc. All Rights Reserved.

#include "SWGUE5GameMode.h"
#include "SWGUE5Character.h"
#include "UObject/ConstructorHelpers.h"

ASWGUE5GameMode::ASWGUE5GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
