// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"

#include <Components/SkeletalMeshComponent.h>
#include <Engine/CollisionProfile.h>
#include "AnimatedItem.generated.h"

/**
 * 
 */
UCLASS()
class SWGUE5_API AAnimatedItem : public AItem
{
	GENERATED_BODY()
public:
	AAnimatedItem();

	UPROPERTY(EditAnywhere)
		USkeletalMeshComponent* SkeletalMesh;
	UPROPERTY(EditAnywhere)
		USpringArmComponent* SpringArm;
	UPROPERTY(EditAnywhere)
		USceneCaptureComponent2D* CaptureComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		UTextureRenderTarget2D* ItemRenderTarget;

	UFUNCTION(BlueprintCallable)
		void SetRenderTarget(UTextureRenderTarget2D* renderTarget);

	UFUNCTION(BlueprintCallable)
		void SetSkeletalMesh(USkeletalMesh* mesh);

	virtual void Tick(float DeltaTime) override;

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
};
