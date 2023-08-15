// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include <Camera/CameraComponent.h>
#include <Components/SceneCaptureComponent2D.h>
#include <GameFramework/SpringArmComponent.h>
#include "Test_GenericItem.generated.h"

/**
 * 
 */
UCLASS()
class SWGUE5_API ATest_GenericItem : public AItem
{
	GENERATED_BODY()
public:
	ATest_GenericItem();

protected:
	virtual void BeginPlay() override;

public:

	virtual void Tick(float DeltaTime) override;
};
