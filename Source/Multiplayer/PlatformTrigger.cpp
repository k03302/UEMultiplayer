// Fill out your copyright notice in the Description page of Project Settings.

#include "PlatformTrigger.h"
#include "Components/BoxComponent.h"

// Sets default values
APlatformTrigger::APlatformTrigger()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    TriggerVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerVolume"));
    if (!ensure(TriggerVolume != nullptr))
        return;
    SetRootComponent(TriggerVolume);
}

// Called when the game starts or when spawned
void APlatformTrigger::BeginPlay()
{
    Super::BeginPlay();
    TriggerVolume->OnComponentBeginOverlap.AddDynamic(
        this, &APlatformTrigger::OnComponentBeginOverlap);
    TriggerVolume->OnComponentEndOverlap.AddDynamic(
        this, &APlatformTrigger::OnComponentEndOverlap);
    UE_LOG(LogTemp, Warning, TEXT("start"));
}

// Called every frame
void APlatformTrigger::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void APlatformTrigger::OnComponentBeginOverlap(
    UPrimitiveComponent *OverlappedComponent,
    AActor *OtherActor,
    UPrimitiveComponent *OtherComp,
    int32 OtherBodyIndex,
    bool bFromSweep,
    const FHitResult &SweepResult)
{
    UE_LOG(LogTemp, Warning, TEXT("Activated: %s"), *OtherComp->GetName());
}

void APlatformTrigger::OnComponentEndOverlap(
    UPrimitiveComponent *OverlappedComponent,
    AActor *OtherActor,
    UPrimitiveComponent *OtherComp,
    int32 OtherBodyIndex)
{
    UE_LOG(LogTemp, Warning, TEXT("Dectivated: %s"), *OtherComp->GetName());
}