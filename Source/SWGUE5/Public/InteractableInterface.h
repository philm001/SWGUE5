// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GameFramework/PlayerController.h"
#include "InteractableInterface.generated.h"

class ASWGMainCharacter;

// This class does not need to be modified.
UINTERFACE(NotBlueprintable, MinimalAPI)
class UInteractableInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class SWGUE5_API IInteractableInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable)
	virtual void Interact(ASWGMainCharacter* Character) = 0;

	UFUNCTION(BlueprintCallable)
		virtual void UseItem(ASWGMainCharacter* Character) {}
};
