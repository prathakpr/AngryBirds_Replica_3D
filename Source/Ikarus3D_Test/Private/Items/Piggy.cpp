// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Piggy.h"
#include "Particles/ParticleSystemComponent.h"
#include "Sound/SoundBase.h"
#include "Kismet/GameplayStatics.h" // Include UGameplayStatics header


// Sets default values
APiggy::APiggy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Piggy = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Piggy"));
	RootComponent = Piggy;
	Piggy->OnComponentHit.AddDynamic(this, &APiggy::OnMeshHit);

	ParticleSystemComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("MyParticleSystem"));
	ParticleSystemComponent->SetupAttachment(RootComponent);
	ParticleSystemComponent->bAutoActivate = false; // Ensure the particle system doesn't automatically start
}

// Called when the game starts or when spawned
void APiggy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APiggy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void APiggy::OnMeshHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (NormalImpulse.Y>1000.f)
	{
		Piggy->SetVisibility(false);
		ParticleSystemComponent->Activate();
		// Only execute once
		if(DoOnce)
			{
				// Play the hit sound
				if (HitSound)
				{
					UGameplayStatics::PlaySound2D(this, HitSound);
				}

				// Destroy the actor after 0.5 seconds
				FTimerHandle TimerHandle;
				GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &APiggy::DestroyActorDelayed, 0.5f, false);
				DoOnce = false;
			}
	}
}
void APiggy::DestroyActorDelayed()
{
	Destroy();
}
