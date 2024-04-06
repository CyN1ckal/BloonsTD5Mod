#include "pch.h"

extern System Main;

void MyMenu::MainMenu()
{
	bool InGame = Main.MasterList->PtrToCoreObjectList->PtrToMonkeyInfo != nullptr;

	ImGui::Begin("Main Menu",NULL, ImGuiWindowFlags_AlwaysAutoResize);

	ImGui::SeparatorText("Bloons Tower Defense 5 Mod");

	if (InGame)
	{
		ImGui::Text("Current Status: In Game!");
		ImGui::Text("Current Round: %u", Main.MasterList->PtrToCoreObjectList->PtrToMonkeyInfo->Round);
	}
	else
	{
		ImGui::Text("Current Status: In Menu.");
		ImGui::Text("Load into a map for more options.");
	}
	ImGui::Separator();

	if (InGame)
	{
		ImGui::Text("Current Money: %f", Main.MasterList->PtrToCoreObjectList->PtrToMonkeyInfo->MonkeyMoney);
		ImGui::SameLine();
		if (ImGui::Button("Add Money"))
			Main.AddMoney(1000);
		ImGui::Text("Current Lives: %u", Main.MasterList->PtrToCoreObjectList->PtrToMonkeyInfo->Lives);
		ImGui::SameLine();
		if (ImGui::Button("Add Lives"))
			Main.AddLives(25);

	}

	ImGui::InputInt("Experience Amount", &Main.DesiredXP);
	if (ImGui::Button("Set Experience"))
	{
		Main.MasterList->PtrToCoreObjectList->PtrToMonkeyStats->XP = Main.DesiredXP;
	}

	ImGui::InputInt("Rank Amount", &Main.DesiredRank);
	if (ImGui::Button("Set Rank"))
	{
		Main.MasterList->PtrToCoreObjectList->PtrToMonkeyStats->Rank = Main.DesiredRank;
	}

	ImGui::InputInt("Monkey Money Amount", &Main.DesiredMonkeyMoney);
	if (ImGui::Button("Set Monkey Money"))
	{
		Main.MasterList->PtrToCoreObjectList->PtrToMonkeyStats->MonkeyMoney = Main.DesiredMonkeyMoney;
	}


	ImGui::End();
}