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
#pragma once

#include "InterfacePanel.hxx"

#include "SGLib.hxx"
#include "CShip.hxx"
#include "ICharacterEntity.hxx"

class ShipRepairPanel : public InterfacePanel
{
public:
	ShipRepairPanel(BaseId const baseId)
		: m_iBaseId(baseId)
	{
		if (++this->m_iPanelInstances > 1) {
			this->m_bPanelActive = false;
		}
		else {
			this->m_bPanelActive = true;
		}

		this->m_pPlayerEntity = SG::get_intransient_data_manager()->get_character_entity_manager()->get_player_character_entity();
		// TODO: Don't hardcode the price factor
		this->m_flRepairPriceFactor = 1;

	};

	virtual ~ShipRepairPanel()
	{
		--this->m_iPanelInstances;
	};

	virtual void render_panel(float const flDelta);

	virtual bool panel_active(void);

	virtual bool prevents_game_input(void) {
		return false;
	};

private:
	ICharacterEntity* m_pPlayerEntity;
	BaseId m_iBaseId;
	float m_flRepairPriceFactor;
	bool m_bPanelActive;
	static int m_iPanelInstances;
};