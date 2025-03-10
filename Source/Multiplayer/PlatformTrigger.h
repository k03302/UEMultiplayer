// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlatformTrigger.generated.h"

UCLASS()
class MULTIPLAYER_API APlatformTrigger : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    APlatformTrigger();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

private:
    UPROPERTY(VisibleAnywhere)
    class UBoxComponent *TriggerVolume;

    UPROPERTY(EditAnywhere)
    TArray<class AMovingPlatform2 *> PlatformsToTrigger;

    UFUNCTION()
    void OnComponentBeginOverlap(
        UPrimitiveComponent *OverlappedComponent,
        AActor *OtherActor,
        UPrimitiveComponent *OtherComp,
        int32 OtherBodyIndex,
        bool bFromSweep,
        const FHitResult &SweepResult);

    UFUNCTION()
    void OnComponentEndOverlap(
        UPrimitiveComponent *OverlappedComponent,
        AActor *OtherActor,
        UPrimitiveComponent *OtherComp,
        int32 OtherBodyIndex);
};
