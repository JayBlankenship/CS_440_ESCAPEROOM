// Fill out your copyright notice in the Description page of Project Settings.


#include "ColorChanger.h"
#include "characterpawn.h"
// Sets default values
AColorChanger::AColorChanger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	CollisionBox->SetGenerateOverlapEvents(true);
	CollisionBox->SetupAttachment(RootComponent);
	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &AColorChanger::OnComponentBeginOverlap);

}

// Called when the game starts or when spawned
void AColorChanger::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AColorChanger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AColorChanger::OnComponentBeginOverlap(UPrimitiveComponent * OverlappedComp,
	AActor * OtherActor,
	UPrimitiveComponent * OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult & SweepResult)
{

	Acharacterpawn* character = Cast<Acharacterpawn>(OtherActor);
	//UE_LOG(LogTemp, Warning, TEXT("Overlap CALLED"));
	if (character)
	{
		//UE_LOG(LogTemp, Warning, TEXT("Overlap CALLED %s"), Cast<String>(character->GetName()));
		character->VisibleComponent->SetMaterial(0, CustomUserValue);
	}
}