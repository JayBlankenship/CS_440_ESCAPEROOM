// Fill out your copyright notice in the Description page of Project Settings.


#include "characterpawn.h"
#include "slidingdoorplusvolume.h"

// Sets default values
Aslidingdoorplusvolume::Aslidingdoorplusvolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	CollisionBox->SetupAttachment(RootComponent);
	VisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisibleComponent"));
	VisibleComponent->AttachToComponent(CollisionBox, FAttachmentTransformRules::KeepRelativeTransform);
	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &Aslidingdoorplusvolume::OnComponentBeginOverlap);
}

// Called when the game starts or when spawned
void Aslidingdoorplusvolume::BeginPlay()
{
	Super::BeginPlay();

	//UE_LOG(LogTemp, Warning, TEXT("Overlap CALLED"));
}

void Aslidingdoorplusvolume::OnComponentBeginOverlap(UPrimitiveComponent * OverlappedComp,
	AActor * OtherActor, 
	UPrimitiveComponent * OtherComp, 
	int32 OtherBodyIndex, 
	bool bFromSweep,
	const FHitResult & SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Overlap CALLED"));
	if ((Cast<Acharacterpawn>(OtherActor)))
	{
		UE_LOG(LogTemp, Warning, TEXT("Overlap CALLED"));
	}
}

// Called every frame
void Aslidingdoorplusvolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

