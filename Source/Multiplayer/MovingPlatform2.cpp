// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform2.h"

// Sets default values
AMovingPlatform2::AMovingPlatform2()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMovingPlatform2::BeginPlay()
{
    Super::BeginPlay();

    SetReplicates(true);
    SetReplicateMovement(true);
}

// Called every frame
void AMovingPlatform2::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (HasAuthority())
    {
        FVector Location = GetActorLocation();
        FVector GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);
        FVector Direction = (GlobalTargetLocation - Location).GetSafeNormal();
        Location += Direction * Speed * DeltaTime;
        SetActorLocation(Location);
    }
}
