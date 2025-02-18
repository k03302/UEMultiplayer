// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class MULTIPLAYER_API AMovingPlatform : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    AMovingPlatform();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(EditAnywhere)
    float Speed;

    UPROPERTY(EditAnywhere)
    float InitAlpha = 0;

    UPROPERTY(VisibleAnywhere)
    USceneComponent *Position1;

    UPROPERTY(VisibleAnywhere)
    USceneComponent *Position2;

private:
    float Alpha;
    USceneComponent *Root;
    USceneComponent *PlatformHolder;
};
