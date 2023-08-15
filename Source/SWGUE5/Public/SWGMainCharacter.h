// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "structs.h"
#include "Item.h"
#include "GameFramework/Character.h"

#include <Net/UnrealNetwork.h>

#include "SWGMainCharacter.generated.h"




UCLASS()
class SWGUE5_API ASWGMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASWGMainCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Server, Reliable, WithValidation)
		void Server_UseItem(TSubclassOf<AItem> ItemSubclass);

	UFUNCTION(BlueprintCallable, Server, Reliable, WithValidation)
		void Server_Interact(FVector Start, FVector End);

	UPROPERTY(ReplicatedUsing = onRep_Stats, EditDefaultsOnly, BlueprintReadWrite)
	float mPlayerHealth = 40.0;

	UPROPERTY(ReplicatedUsing = onRep_Stats, EditDefaultsOnly, BlueprintReadWrite)
	float mPlayerHunger = 40.0;

	UPROPERTY(ReplicatedUsing = onReplicateInventoryItems, BlueprintReadWrite)
		TArray<FItemData> InventoryItems;

	UFUNCTION()
		void onReplicateInventoryItems();

	UFUNCTION(BlueprintImplementableEvent)
		void AddItemandUpdateInventortyWidgetTest(FItemData ItemStored, const TArray<FItemData> &CurrentInventory = TArray<FItemData>());

	UFUNCTION(BlueprintImplementableEvent)
		void UpdateInventoryWidget(const TArray<FItemData> &NewInventoryItems);

	UFUNCTION(BlueprintCallable)
		void Interact(FVector Start, FVector End);

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		bool m_male = true;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	void addHealth(float HealthAdded);

	UFUNCTION(BlueprintCallable)
	void removeHungry(float value);

	UFUNCTION(BlueprintCallable)
	void UseItem(TSubclassOf<AItem> ItemSubclass);

	UFUNCTION(BlueprintNativeEvent)
	void UpdateStats(float NewHunger, float NewHealth);

	UFUNCTION(BlueprintCallable)
		void InteractBP();

	UFUNCTION(BlueprintCallable)
		bool isMale() { return m_male;  }

	UFUNCTION()
		void onRep_Stats();

	void AddInventoryItem(FItemData item);

};
