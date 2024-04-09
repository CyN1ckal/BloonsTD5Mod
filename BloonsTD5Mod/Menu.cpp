#include "pch.h"

extern System Main;

void MyMenu::MainMenu()
{
	bool InGame = Main.MasterList->PtrToCoreObjectList->PtrToMonkeyInfo != nullptr;

	ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoTitleBar;

	ImGuiStyle& style = ImGui::GetStyle();
	style.FrameRounding = 4;
	style.FrameBorderSize = 1;


	ImGui::Begin("Main Menu",NULL, window_flags);

	if (InGame)
	{
		ImGui::Text("Current Status:"); 
		ImGui::SameLine();
		ImGui::TextColored(ImVec4(0.0f, 1.0f, 0.0f, 1.0f), "In Game!");
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
		//ImGui::Text("Current Money: %f", Main.MasterList->PtrToCoreObjectList->PtrToMonkeyInfo->MonkeyMoney);
		//ImGui::SameLine();
		//if (ImGui::Button("Add Money"))
		//	Main.AddMoney(1000);
		//ImGui::Text("Current Lives: %u", Main.MasterList->PtrToCoreObjectList->PtrToMonkeyInfo->Lives);
		//ImGui::SameLine();
		//if (ImGui::Button("Add Lives"))
		//	Main.AddLives(25);

		if (ImGui::Button("Add Money"))
			Main.AddMoney(Main.AddMoneyAmount);
		ImGui::SameLine();
		ImGui::PushItemWidth(-FLT_MIN);
		ImGui::InputDouble("Money Amount", &Main.AddMoneyAmount,100,1000);
		ImGui::PopItemWidth();

		if (ImGui::Button("Add Lives"))
			Main.AddLives(Main.AddLivesAmount);
		ImGui::SameLine();
		ImGui::PushItemWidth(-FLT_MIN);
		ImGui::InputInt("Lives Amount", &Main.AddLivesAmount);
		ImGui::PopItemWidth();


	}

	if (ImGui::Button("Set Experience"))
	{
		Main.MasterList->PtrToCoreObjectList->PtrToMonkeyStats->XP = Main.DesiredXP;
	}
	ImGui::SameLine();
	ImGui::PushItemWidth(-FLT_MIN);
	ImGui::InputInt("Experience Amount", &Main.DesiredXP);
	ImGui::PopItemWidth();

	if (ImGui::Button("Set Rank"))
	{
		Main.MasterList->PtrToCoreObjectList->PtrToMonkeyStats->Rank = Main.DesiredRank;
	}
	ImGui::SameLine();
	ImGui::PushItemWidth(-FLT_MIN);
	ImGui::InputInt("Rank Amount", &Main.DesiredRank);
	ImGui::PopItemWidth();

	if (ImGui::Button("Set Monkey Money"))
	{
		Main.MasterList->PtrToCoreObjectList->PtrToMonkeyStats->MonkeyMoney = Main.DesiredMonkeyMoney;
	}
	ImGui::SameLine();
	ImGui::PushItemWidth(-FLT_MIN);
	ImGui::InputInt("Monkey Money Amount", &Main.DesiredMonkeyMoney);
	ImGui::PopItemWidth();

	if (ImGui::Button("Set Tokens"))
	{
		Main.MasterList->PtrToCoreObjectList->PtrToMonkeyStats->MonkeyTokens = Main.DesiredTokens;
	}
	ImGui::SameLine();
	ImGui::PushItemWidth(-FLT_MIN);
	ImGui::InputInt("Token Amount", &Main.DesiredTokens);
	ImGui::PopItemWidth();

	ImGui::Checkbox("Infinite Special Agents", &Main.InfiniteSpecialAgents);

	ImGui::End();
}

void MyMenu::DebugMenu()
{
	ImGui::Begin("Debug Menu");

	if (ImGui::Button("Toggle On"))
	{
		Main.ToggleInfiniteSpecialAgents(1);
	}

	if (ImGui::Button("Toggle Off"))
	{
		Main.ToggleInfiniteSpecialAgents(0);
	}

	ImGui::End();
}