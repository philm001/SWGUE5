// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "../AnimatedItem.h"
#include "ArmorObject.generated.h"


USTRUCT(BlueprintType)
struct SWGUE5_API FArmorDTStruct : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		FString InternalName; // The name of the name used in UE

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		FText ItemGameName; // The name will appear in game

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		TSubclassOf<AArmorObject> ItemBluePrintClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		UTextureRenderTarget2D* Render_Target;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		USkeletalMesh* SkeletaleMeshReference;
};

/**
 * 
 */
UCLASS()
class SWGUE5_API AArmorObject : public AAnimatedItem
{
	GENERATED_BODY()
	
public:
	UArmorTypeEnum GetArmorType() { return ItemData.ArmorType; }
};
