// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform2.h"

// Sets default values
AMovingPlatform2::AMovingPlatform2()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    bMovingForward = true;
    DistanceMoved = 0;
}

// Called when the game starts or when spawned
void AMovingPlatform2::BeginPlay()
{
    Super::BeginPlay();

    SetReplicates(true);
    SetReplicateMovement(true);

    GlobalStartLocation = GetActorLocation();
    GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);

    FVector Diff = GlobalTargetLocation - GlobalStartLocation;
    GlobalMoveDirection = Diff.GetSafeNormal();
    MoveDistance = Diff.Size();
}

// Called every frame
void AMovingPlatform2::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (HasAuthority())
    {
        FVector Location = GetActorLocation();

        float deltaDistance = Speed * DeltaTime;
        Location += (bMovingForward ? 1 : -1) * GlobalMoveDirection * deltaDistance;
        SetActorLocation(Location);
        DistanceMoved += deltaDistance;

        if (DistanceMoved >= MoveDistance)
        {
            DistanceMoved = 0;
            bMovingForward = !bMovingForward;
        }
    }
}
