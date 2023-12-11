/**
 * Copyright (C) 2020 Jacob Farnsworth.
 *
 * This file is part of the Spaced Out 4 project.
 *
 * Spaced Out 4 is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published
 * by the Free Software Foundation, version 2.
 *
 * Spaced Out 4 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 *
 */
#include "ShipRepairPanel.hxx"
#include "SGLib.hxx"
#include <sstream>

int ShipRepairPanel::m_iPanelInstances = 0;

void ShipRepairPanel::render_panel(float const flDelta) 
{
	ICharacterEntity* pPlayerEntity = SG::get_intransient_data_manager()->get_character_entity_manager()->get_player_character_entity();
	int m_iMoney = this->m_pPlayerEntity->get_inventory()->get_money();
	int m_iMetal = this->m_pPlayerEntity->get_inventory()->get_metal();

	ImGui::Begin("Repair Ship", nullptr, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoResize);

	ImGui::Text("Money: %d", m_iMoney);
	ImGui::Text("Metal: %d", m_iMetal);

	ImGui::Separator();

	int iHealthPerMetal = 20;

	// TODO: Make the player's Bartering stat have an effect on price.
	int iMoneyPerHealth = 5 * m_flRepairPriceFactor;

	float m_flMaxHealth = m_pPlayerEntity->get_max_health();
	float m_flHealth = m_pPlayerEntity->get_health();
	int m_iHealthMissing = std::ceil((m_flMaxHealth - m_flHealth) / iHealthPerMetal);
	int m_iAmountAfforded = 0;

	ImGui::Text("Full hull repair: %d metal %d credits", m_iHealthMissing, m_iHealthMissing * iMoneyPerHealth);
	if (m_iMoney >= m_iHealthMissing * iMoneyPerHealth && m_iMetal >= m_iHealthMissing)
	{
		ImGui::Text("You can afford a full repair");
		m_iAmountAfforded = m_iHealthMissing;
	}
	else {
		ImGui::Text("You can afford %d hull health", std::min(m_iMoney / iMoneyPerHealth, m_iMetal) * iHealthPerMetal);
		m_iAmountAfforded = std::min(m_iMoney / iMoneyPerHealth, m_iMetal);
	}

	if (ImGui::Button("Repair")) 
	{
		if(m_iAmountAfforded > 0)
		{
			this->m_pPlayerEntity->set_health(m_pPlayerEntity->get_health() + m_iAmountAfforded * iHealthPerMetal);

			this->m_pPlayerEntity->get_inventory()->adjust_metal(-m_iAmountAfforded);
			this->m_pPlayerEntity->get_inventory()->adjust_money(-m_iAmountAfforded * iMoneyPerHealth);

			//TODO: Add repair sound
		}
	}

	ImGui::Separator();

	if (ImGui::Button("Leave")) 
	{
		this->m_bPanelActive = false;
	}

	ImGui::End();
}

bool ShipRepairPanel::panel_active(void) 
{
	return this->m_bPanelActive;
}