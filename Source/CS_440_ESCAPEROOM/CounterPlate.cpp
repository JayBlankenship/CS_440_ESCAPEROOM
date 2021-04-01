// Fill out your copyright notice in the Description page of Project Settings.


#include "CounterPlate.h"
#include "Components/StaticMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "Materials/MaterialInstanceDynamic.h"

// Sets default values
ACounterPlate::ACounterPlate()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = root;

	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	mesh->AttachTo(root);


	collisionCapsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	collisionCapsule->InitCapsuleSize(120.f, 110.f);
	collisionCapsule->SetupAttachment(RootComponent);
	collisionCapsule->OnComponentBeginOverlap.AddDynamic(this, &ACounterPlate::BeginOverlap);
	collisionCapsule->OnComponentEndOverlap.AddDynamic(this, &ACounterPlate::EndOverlap);

	currCount = 0;
}

// Called when the game starts or when spawned
void ACounterPlate::BeginPlay()
{
	Super::BeginPlay();

	daynamicM = mesh->CreateDynamicMaterialInstance(0);
	if (ID == 1) {
		daynamicM->SetVectorParameterValue(FName("Color"), FLinearColor::Yellow);
	}
	else if (ID == 2) {
		daynamicM->SetVectorParameterValue(FName("Color"), FLinearColor(FColor::Purple));
	}
	else {
		daynamicM->SetVectorParameterValue(FName("Color"), FLinearColor::Green);
	}

	maxCount = ID * 5;
	
}

// Called every frame
void ACounterPlate::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ACounterPlate::BeginOverlap(UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{

	if (currCount == maxCount) {
		daynamicM->SetVectorParameterValue(FName("Color"), FLinearColor::Black);
		return;
	}

	if (ID == 1) {
		daynamicM->SetVectorParameterValue(FName("Color"), FLinearColor::Yellow);
	}
	else if (ID == 2) {
		daynamicM->SetVectorParameterValue(FName("Color"), FLinearColor(FColor::Purple));
	}
	else {
		daynamicM->SetVectorParameterValue(FName("Color"), FLinearColor::Green);
	}

	
}


void ACounterPlate::EndOverlap(UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex)
{
	
	if (currCount != maxCount) {
		daynamicM->SetVectorParameterValue(FName("Color"), FLinearColor::Blue);
		currCount++;
	}
}

