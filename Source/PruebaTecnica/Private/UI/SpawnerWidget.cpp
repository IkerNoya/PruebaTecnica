// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/SpawnerWidget.h"

void USpawnerWidget::ExecuteSpawn()
{
	if (OnExecuteSpawn.IsBound())
	{
		OnExecuteSpawn.Broadcast(AmountToSpawn, Lifetime);
	}
}

void USpawnerWidget::OnClose()
{
	if (OnWidgetClose.IsBound())
	{
		OnWidgetClose.Broadcast();
	}
}
