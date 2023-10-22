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
#include "CLandedState.hxx"
#include "BaseHubPanel.hxx"

CLandedState::CLandedState(BaseId const iBaseId)
	: m_iBaseId(iBaseId)
{
}

CLandedState::~CLandedState()
{
}

void CLandedState::state_initializing(void)
{
	SG::get_interface_manager()->add_panel(new BaseHubPanel(this->m_iBaseId));

	this->m_bInitialized = true;
}

void CLandedState::state_prerender_tick(sf::View &, sf::RenderWindow &, float const)
{
}

void CLandedState::state_render_world_tick(sf::View &, sf::RenderWindow &, float const)
{
}

void CLandedState::state_render_world_ui_tick(sf::View &, sf::RenderWindow &, float const)
{
}

void CLandedState::state_render_ui_tick(sf::View &, sf::RenderWindow &, float const)
{
}

void CLandedState::state_postrender_tick(sf::RenderWindow &, float const)
{
}

void CLandedState::state_terminating(void)
{
}

void CLandedState::state_process_event(sf::View &, sf::RenderWindow &, sf::Event &)
{
}

bool CLandedState::state_terminated(void)
{
	return false;
}

bool CLandedState::state_game_paused(void)
{
	return false;
}

bool CLandedState::state_render_world(void)
{
	return true;
}

bool CLandedState::state_render_ui(void)
{
	return true;
}