// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
//#include "SWGMainCharacter.h"
#include "InteractableInterface.h"
#include "Components/StaticMeshComponent.h"
#include "structs.h"
#include "Engine/World.h"
#include <Camera/CameraComponent.h>
#include <Components/SceneCaptureComponent2D.h>
#include <GameFramework/SpringArmComponent.h>

#include "Item.generated.h"

class ASWGMainCharacter;


UCLASS(Blueprintable)
class SWGUE5_API AItem : public AActor, public IInteractableInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();

protected:

	UPROPERTY(EditDefaultsOnly, Category = "Item")
		FItemData ItemData;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	 
public:	

	AItem(FItemData& Data)
	{
		ItemData = Data;
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool b_IsInsideInventory = false;

	UFUNCTION(BlueprintImplementableEvent)
		void NotifyInteractEvent(FItemData &ReferenceData);

	UFUNCTION(BlueprintCallable)
		FItemData GetItemData() const { return ItemData; }

	UFUNCTION(BlueprintCallable)
		void SetItemData(FItemData ItemDataToSet) { ItemData = ItemDataToSet; }

	UFUNCTION(BlueprintCallable)
		void DuplicateItem();

	UFUNCTION(BlueprintCallable)
		virtual void Interact(class ASWGMainCharacter* Character) override;

	UFUNCTION(BlueprintCallable)
		virtual void UseItem(ASWGMainCharacter* Character) override;

	FString TestFunction() const { return FString("OUr Test String"); }

	
};
