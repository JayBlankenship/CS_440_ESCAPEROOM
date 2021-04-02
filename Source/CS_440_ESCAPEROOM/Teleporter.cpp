// Fill out your copyright notice in the Description page of Project Settings.


#include "Teleporter.h"
#include "characterpawn.h"

// Sets default values
ATeleporter::ATeleporter()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	CollisionBox->SetGenerateOverlapEvents(true);
	CollisionBox->SetupAttachment(RootComponent);
	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ATeleporter::OnComponentBeginOverlap);
	//CollisionBox->OnComponentEndOverlap.AddDynamic(this, &ATeleporter::OnComponentEndOverlap);
}

// Called when the game starts or when spawned
void ATeleporter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATeleporter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//UE_LOG(LogTemp, Warning, TEXT("Overlap CALLED"));
	//GetWorld()->GetFirstPlayerController()->GetPawn()->SetActorLocation(CustomUserValue);

}

void ATeleporter::OnComponentBeginOverlap(UPrimitiveComponent * OverlappedComp,
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
		
		//GetWorld()->GetFirstPlayerController()->GetPawn()->SetActorLocation(CustomUserValue);
		//UE_LOG(LogTemp, Warning, TEXT("Overlap CALLED %s"), Cast<String>(character->GetName()));
		character->SetActorLocation(CustomUserValue);
		//character->SetActorLocationAndRotation(CustomUserValue, character->GetActorRotation());
	}
}