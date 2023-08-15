// Fill out your copyright notice in the Description page of Project Settings.


#include "StaticItem.h"
#include "SWGMainCharacter.h"

AStaticItem::AStaticItem()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	RootComponent = StaticMesh;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	SpringArm->SetRelativeRotation(FRotator(0.0f, 0.0f, 180.0f));
	SpringArm->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 50.0f), FRotator(0.0f, 0.0f, 0.0f));
	SpringArm->TargetArmLength = 100.0f;
	SpringArm->bEnableCameraLag = true;
	//SpringArm->CameraLagSpeed = 3.0f;

	CaptureComponent = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("Scene_Capture"));
	CaptureComponent->SetupAttachment(SpringArm, USpringArmComponent::SocketName);

	ItemData.ItemClass = this->StaticClass();
}

void AStaticItem::SetRenderTarget(UTextureRenderTarget2D* renderTarget)
{
	CaptureComponent->TextureTarget = renderTarget;
}

void AStaticItem::SetStaticMesh(UStaticMesh* mesh)
{
	StaticMesh->SetStaticMesh(mesh);
}

void AStaticItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FRotator worldRotation = SpringArm->GetComponentRotation();
	worldRotation.Add(0, 30.0f * DeltaTime, 0.0);
	SpringArm->SetWorldRotation(worldRotation);
}


void AStaticItem::BeginPlay()
{
	Super::BeginPlay();
	CaptureComponent->ShowOnlyActorComponents(this, true);
}
