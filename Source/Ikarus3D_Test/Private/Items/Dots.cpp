// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Dots.h"
#include "Components/SphereComponent.h"

// Sets default values
ADots::ADots()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Dot = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Dot"));
	RootComponent = Dot;
	Dot->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

// Called when the game starts or when spawned
void ADots::BeginPlay()
{
	Super::BeginPlay();
	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ADots::DestroyActorDelayed, 0.02f, false);
}

// Called every frame
void ADots::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void ADots::DestroyActorDelayed()
{
	Destroy();
}
