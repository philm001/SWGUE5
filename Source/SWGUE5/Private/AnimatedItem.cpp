// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimatedItem.h"
#include "SWGMainCharacter.h"

AAnimatedItem::AAnimatedItem()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
	RootComponent = SkeletalMesh;

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

	SkeletalMesh->BodyInstance.bNotifyRigidBodyCollision = 1;
	SkeletalMesh->SetCollisionProfileName(UCollisionProfile::BlockAllDynamic_ProfileName);
}

void AAnimatedItem::SetRenderTarget(UTextureRenderTarget2D* renderTarget)
{
	CaptureComponent->TextureTarget = renderTarget;
}


void AAnimatedItem::SetSkeletalMesh(USkeletalMesh* mesh)
{
	SkeletalMesh->SetSkeletalMesh(mesh);
}

void AAnimatedItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FRotator worldRotation = SpringArm->GetComponentRotation();
	worldRotation.Add(0, 30.0f * DeltaTime, 0.0);
	SpringArm->SetWorldRotation(worldRotation);
}

void AAnimatedItem::BeginPlay()
{
	Super::BeginPlay();
	CaptureComponent->ShowOnlyActorComponents(this, true);
}
