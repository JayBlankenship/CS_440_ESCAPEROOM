// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuHUD.h"
#include "SMainMenuWidget.h"
#include "SLoginWidget.h"
#include "Engine.h"

void AMainMenuHUD::BeginPlay()
{
	Super::BeginPlay();
	showLogin();
}

void AMainMenuHUD::showLogin()
{
	if (GEngine && GEngine->GameViewport) {
		LoginWidget = SNew(SLoginWidget).OwnerHUD(this);
		GEngine->GameViewport->AddViewportWidgetContent(SAssignNew(MenuWidgetContainer, SWeakWidget).PossiblyNullContent(LoginWidget.ToSharedRef()));
		LoginWidget->SetVisibility(EVisibility::Visible);
	}

	if (PlayerOwner)
	{
		PlayerOwner->bShowMouseCursor = true;
		PlayerOwner->SetInputMode(FInputModeUIOnly());
	}
}

void AMainMenuHUD::removeLogin()
{

}

void AMainMenuHUD::showPlayMenu()
{

}

void AMainMenuHUD::removePlayMenu()
{

}


