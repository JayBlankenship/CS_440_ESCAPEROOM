// Fill out your copyright notice in the Description page of Project Settings.


#include "PressurePlate.h"
#include "Components/StaticMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "Materials/MaterialInstanceDynamic.h"

int32 APressurePlate::prevPlate = -1;
bool APressurePlate::reset = false;

// Sets default values
APressurePlate::APressurePlate()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = root;

	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	mesh->AttachTo(root);

	
	collisionCapsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	collisionCapsule->InitCapsuleSize(40.f, 40.f);
	collisionCapsule->SetupAttachment(RootComponent);
	collisionCapsule->OnComponentBeginOverlap.AddDynamic(this, &APressurePlate::BeginOverlap);
	collisionCapsule->OnComponentEndOverlap.AddDynamic(this, &APressurePlate::EndOverlap);
}

// Called when the game starts or when spawned
void APressurePlate::BeginPlay()
{
	Super::BeginPlay();
	
	daynamicM = mesh->CreateDynamicMaterialInstance(0);
	//SetActorRelativeLocation(theLocation, false, 0, ETeleportType::None);
	Location = GetActorLocation();
}

// Called every frame
void APressurePlate::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APressurePlate::BeginOverlap(UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp && daynamicM != nullptr) {

		if (Location.X == 1450.f) {
			if (APressurePlate::prevPlate == -1) {
				daynamicM->SetVectorParameterValue(FName("Color"), FLinearColor::Green);
				APressurePlate::prevPlate = 0;
			}
			
		}

		if (Location.X == 950.f) {
			
			if (APressurePlate::prevPlate == 0) {
				daynamicM->SetVectorParameterValue(FName("Color"), FLinearColor::Green);
				APressurePlate::prevPlate = 1;
			}
			else {
				daynamicM->SetVectorParameterValue(FName("Color"), FLinearColor::Red);
				APressurePlate::reset = true;
			}
		}

		if (Location.X == 1200.f) {

			if (APressurePlate::prevPlate == 1) {
				daynamicM->SetVectorParameterValue(FName("Color"), FLinearColor::Green);
				APressurePlate::prevPlate = 2;
			}
			else {
				daynamicM->SetVectorParameterValue(FName("Color"), FLinearColor::Red);
				APressurePlate::reset = true;
			}
			
		}

		
		/*
		if (Location.X == 1450.f) {
			daynamicM->SetVectorParameterValue(FName("Color"), FLinearColor::Green);

		}
		else if (Location.X == 1200.f) {
			daynamicM->SetVectorParameterValue(FName("Color"), FLinearColor::Red);
		}
		else {
			daynamicM->SetVectorParameterValue(FName("Color"), FLinearColor::Yellow);
		}
		*/
	}

	//UE_LOG(LogTemp, Warning, TEXT("counter %d"), counter);
}

void APressurePlate::EndOverlap(UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex)
{
	
	if (APressurePlate::reset) {
		daynamicM->SetVectorParameterValue(FName("Color"), FLinearColor::Blue);
		APressurePlate::reset = false;
	}
	
	//daynamicM->SetVectorParameterValue(FName("Color"), FLinearColor::Blue);
	//UE_LOG(LogTemp, Warning, TEXT("counter %d"), counter);
}

