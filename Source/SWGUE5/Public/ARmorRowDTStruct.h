// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedStruct.h"
#include "CoreMinimal.h"
#include "AnimatedItem.h"
#include "Objects/ArmorObject.h"
#include "ARmorRowDTStruct.generated.h"

/**
 * 
 *///This is marked for deletion
USTRUCT(BlueprintType)
struct FArmorRowDTStruct
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		FString InternalName; // The name of the name used in UE

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		FText ItemGameName; // The name will appear in game

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		TSubclassOf<AArmorObject> ItemBluePrintClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		AArmorObject* Object_BP_F;// Blueprint for the Female version

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		AArmorObject* Object_BP_M; // Blueprint for the Male version

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		UTextureRenderTarget2D* Render_Target;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		USkeletalMeshComponent* SkeletaleMeshReference;
};

