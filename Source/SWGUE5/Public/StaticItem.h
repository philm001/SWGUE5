// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "StaticItem.generated.h"

/**
 * 
 */
UCLASS()
class SWGUE5_API AStaticItem : public AItem
{
	GENERATED_BODY()
public:
	AStaticItem();

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* StaticMesh;
	UPROPERTY(EditAnywhere)
		USpringArmComponent* SpringArm;
	UPROPERTY(EditAnywhere)
		USceneCaptureComponent2D* CaptureComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		UTextureRenderTarget2D* ItemRenderTarget;

	UFUNCTION(BlueprintCallable)
		void SetRenderTarget(UTextureRenderTarget2D* renderTarget);

	UFUNCTION(BlueprintCallable)
		void SetStaticMesh(UStaticMesh* mesh);

	virtual void Tick(float DeltaTime) override;



protected:
	UPROPERTY(EditDefaultsOnly, Category = "Item")
		class UStaticMeshComponent* itemMesh;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
