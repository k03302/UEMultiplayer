// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    Position1 = CreateDefaultSubobject<USceneComponent>(TEXT("Position1"));
    Position2 = CreateDefaultSubobject<USceneComponent>(TEXT("Position2"));
    PlatformHolder = CreateDefaultSubobject<USceneComponent>(TEXT("Platform"));

    SetRootComponent(Root);
    Position1->SetupAttachment(Root);
    Position2->SetupAttachment(Root);
    PlatformHolder->SetupAttachment(Root);
}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
    Super::BeginPlay();

    Alpha = InitAlpha;
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (HasAuthority())
    {
        Alpha = FMath::Clamp(Alpha + DeltaTime * Speed, 0.0f, 1.0f);
        if (Alpha == 1 || Alpha == 0)
        {
            Speed = -Speed;
        }

        FVector NewPlatformLocation = Position1->GetComponentLocation() * Alpha + Position2->GetComponentLocation() * (1 - Alpha);
        PlatformHolder->SetWorldLocation(NewPlatformLocation);
    }
}
