
/* $Id$
 * EOSERV is released under the zlib license.
 * See LICENSE.txt for more info.
 */

#ifndef PLAYER_HPP_INCLUDED
#define PLAYER_HPP_INCLUDED

#include <string>

class Player;

#include "eoclient.hpp"
#include "world.hpp"
#include "character.hpp"
#include "eoconst.hpp"

/**
 * Object representing a player, but not a character
 */
class Player
{
	public:
		int login_time;
		bool online;
		unsigned int id;
		std::string username;
		std::string password;

		Player(std::string username, World *);

		std::vector<Character *> characters;
		Character *character;

		static bool ValidName(std::string username);
		bool AddCharacter(std::string name, Gender gender, int hairstyle, int haircolor, Skin race);
		void ChangePass(std::string password);

		World *world;
		EOClient *client;

		~Player();
};


#endif // PLAYER_HPP_INCLUDED