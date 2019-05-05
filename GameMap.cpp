/*

Name: Christopher Lochhead

Student ID: B00306187

I declare that the following code was produced by Chris Lochhead as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/


#include "GameMap.h"


void GameMap::Intro(Player* player1, string Name) { // game intro

	int choice;
	cout << Name << " is a young person heading from Edinburgh to Glasgow to visit family for the Christmas holidays. Getting there " << "\n";
	cout <<"seems easy enough right? However, " << Name << " has no idea what they were in for when they arrived at central station that" << "\n";
	cout << "fateful day." << endl;

	system("pause");
	system("CLS");

	do{
	cout << "You arrive at central station and head outside to Argyl street, you are immidiately taken aback as your first impression of " << "\n";
	cout << "Glasgow is a horrible smell of sewage, 12 year olds smoking cigarettes outside a Mcdonalds, and what appears to be a heavily pregnant teenager" << "\n";
	cout << "chasing a Rottweiler down the street with a sledgehammer. You feel you have gotten more than you bargained for with this city, do you: " << "\n";

	cout << "  " << "\n" << " " << "\n";

	cout << "0: run back into the train station and go back home?  " << "\n";
	cout << "1: turn left towards the street past the homeless people and smoking teenagers?  " << "\n";
	cout << "2: turn right where you can see buses going up and down the next street  " << "\n";
	cout << "3: check your bag " << "\n";
	cout << "4: change the game difficulty" << "\n";
	cin >> choice;

	switch (choice) {
	case 0:
		system("CLS");
		cout << "Being a total shitebag, you get a run up the stairs and get a train right back to shit-town," << "\n";
		cout << "or wherever the fuck you came from. " << "\n";
		system("pause");
		exit(0);

		break;
	case 1:
		system("CLS");
		CallScript(player1, 1); // progress the story
		break;
	case 2:
		system("CLS"); 
		CallScript(player1, 2); // progress the story
		break;
	case 3:
		system("CLS");
		checkBag();  // check inventory
		break;
	case 4:
		int newDiff;
		system("CLS");
		registerObserver(player1);
		cout << "enter a new difficulty, from 1 to 3" << endl;
		cin >> newDiff;
		if(newDiff < 1 || newDiff > 3) {

			cout << "invalid entry, try again" << endl;
			cin >> newDiff;
		}
		notifyObserver(newDiff);
		player1->setDifficulty(this->getDifficulty());
		cout << "new difficulty" << this->getDifficulty() << endl;
		break;
	default:
		cout << " invalid choice" << endl;
		break;
		}

	} while (choice != 1 || choice != 2);

} 
void GameMap::HealthScript(Player* player1) {

	int choice;
	int MaximumPainKillers = 3;
	cout << " You enter the pharmacy and see an assortment of painkillers, what would you like to buy?" << endl;
	cout << "1: buy painkillers" << endl;
	cout << "2: leave" << endl;

	cin >> choice;
	switch (choice) {
	case 1:
		//call player function to increase health item count whilst reducing currency
		player1->BuyPainKillers(MaximumPainKillers);	
		system("CLS");
		break;
	case 2:
		//leave
		cout << "you leave the shop" << endl;
		system("pause");
		system("CLS");
		break;
	}
}

void GameMap::CallScript(Player* player1, int ScriptNumber) { // This is the text based version of displaying the whole game environment

	if (ScriptNumber == 1) {
		int choice;
		cout << "You walk down the street, uncomfortably aware of all the eyes that are on you. " << "\n";
		cout << "Unsurprisingly, as soon as you are within 10 feet of a local junkie, you are confronted " << "\n";
		cout << "and threatened with what appears to be a screwdriver, by a man with visible body odour, " << "\n";
		cout << "and even more visible genitalia, this man is clearly unhinged and your initial unease about this " << "\n";
		cout << "situation has descended into outright fear, do you: " << "\n";
		cout << " " << "\n" << "\n";

		cout << "0: diffuse the situation by giving him £20" << "\n";
		cout << "1: take this pricks square go, your strong, you played under 16s lacrosse in school" << "\n";
		cout << "2: shout for help and try to run away " << "\n";

		cin >> choice;
		system("CLS");
		switch (choice) {
		case 0:
			cout << "you reach into your bag and attempt to give the man £20, but rather unfortunately," << "\n";
			cout << "all of your money falls out as you scramble in fear. The junkie, frankly dissapointed " << "\n";
			cout << "that you would try to lowball him, proceeds to stab you in and around the abdomen, until " << "\n";
			cout << "you are no longer consisting of life, Goodbye. " << "\n";
			system("pause");
			exit(0);
			break;
		case 1:
			//initiate battle
			EnemyEntity* junkie = new Enemy("junkie", 5, 2, 1);
			BattleSystem*  battle = new NormalTextBattleSystem(player1, junkie);
			bool fight = battle->fight(player1, junkie);
			if (fight == true) {
				//win
				CallScript(player1, 3);
			}
			else {
				//lose
				exit(0);
			}
			delete battle;
			delete junkie;
			
			//destroy instance of battle and junkie;
		}

	}
	if (ScriptNumber == 2) {

		// turns and goes to the bus
		int choice;
		do{
		cout << "You decide to walk to the street with the buses, you feel terrified as a " << "\n";
		cout << "group of 16 year olds dressed up like a track team begin shouting obscenities at you. " << "\n";
		cout << "you move swiftly on and find a bus stop. You awkwardly look around the fat elderly woman " << "\n";
		cout << "sleeping in the bus stop infront of the bus schedule, but you cant make head or tails of " << "\n";
		cout << "anything. All of the sudden, a man with very few teeth comes up to you and asks in a crushingly " << "\n";
		cout << "uneducated accent, and asks if you need help. " << "\n";
		cout << "Do you: " << "\n";
		cout << " " << "\n" << "\n";
		cout << "1: ignore this man and go to the next bus stop up the street. " << "\n";
		cout << "2: ask him about the bus routes. " << "\n";
		cout << "3: check your bag " << "\n";
		
			cin >> choice;

			switch (choice) {
			case 1:
				system("CLS");
				cout << "You ignore the man, which he clearly isnt happy with this. He gets angrier and angrier, frankly " << "\n";
				cout << "just making a scene on this busy street. You start to walk away and he follows you, you refuse to " << "\n";
				cout << "turn around and acknowledge the man, before you here a loud expletive and feel a sharp thud plant into your " << "\n";
				cout << "spine. All the sudden your legs go cold and give way. The last thing you remember is throwing up on yourself " << "\n";
				cout << "as you see a five year old boy smoking a cigarette, looking on at your corpse in a completely deadpan manner. " << "\n";
				system("pause");
				exit(0);
				break;
			case 2:
				system("CLS");
				CallScript(player1, 5);
				break;
			case 3:
				system("CLS");
				player1->checkBag();
				break;
			}
		} while (choice != 1 || choice != 2);

	}
	if (ScriptNumber == 3) {

		// kills junkie and reaches four corners
		int choice;
		system("CLS");
		cout << "The junkie collapses, this dude is no longer a threat, you notice his pockets are crammed with stuff" << "\n";
		cout << "do you: " << "\n";
		cout << "1: rifle through his pockets" << "\n";
		cout << "2: head on to the intersection " << "\n";

		do {
			cin >> choice;
			switch (choice) {

			case 1:
				player1->recievePickup();
				CallScript(player1, 4);
				break;
			case 2:
				CallScript(player1, 4);
				break;
			}
		} while (choice != 1 || choice != 2);

		system("pause");

	}

	if (ScriptNumber == 4) {
		int choice;
		// gets to shop at four corners
		cout << "You triumphantly walk over the body of that hapless criminal, giving him a good kick in the spine for his trouble." << "\n";
		cout << "Walking ahead, you reach an intersection full of shops, you figure you have time to visit one before you should try" << "\n";
		cout << "and catch a bus to your families home." << "\n";
		cout << "Do you: " << "\n";

		cout << "1: visit Frasers Pharmacy (Health)" << "\n"; 
		cout << "2: visit sports direct (Armour)" << "\n";
		cout << "3: just move on without visiting a shop" << "\n";
		cout << "4: check bag" << "\n";
		do {
			cin >> choice;

			switch (choice) {
			case 1:
				HealthScript(player1);
				CallScript(player1, 12);
				break;
			case 2:
				player1->BuyArmour();
				CallScript(player1, 12);
				break;
			case 3:
				CallScript(player1, 12);
				break;
			case 4:
				player1->checkBag();
				break;
			}
		} while (choice != 1 || choice != 2);

		

	}
	if (ScriptNumber == 5) {

		int choice;
		cout << "You ask the man about the bus routes, and through his thick as soup accent, you think he says he is " << "\n";
		cout << "heading the same direction as you, and you should come with him. You get on the 60 bus, and the first " << "\n";
		cout << "thing you notice is the awful smell of urine. Despite being empty, the man sits uncomfortably close to you " << "\n";
		cout << "and offers you a strange looking cigarette, which you take, fearing for your life. After taking a large toak, you " << "\n";
		cout << "realise it was not cannabis you just smoked. " << "\n";

		cout << "	The next 12 hours are a blur and you wake up with a horrific headache, in some sort of warehouse full of " << "\n";
		cout << "sleeping bags, syringes and spray paint cans. Upon looking into a piece of broken glass, you discover you have " << "\n";
		cout << "a facial tattoo of a poorly drawn naked woman. Shaken and in extreme pain, you make your way to the exit. " << "\n";
		cout << "Outside you discover you are in an abandoned business park in bishopbriggs in the middle of the night " << "\n";
		cout << "do you: " << "\n" << "\n" << "\n";
		cout << "1: phone a taxi  " << "\n";
		cout << "2: start walking " << "\n";
		cout << "3: check your bag " << "\n";

		cin >> choice;

		switch (choice)
		{
		case 1:
			CallScript(player1, 6);
			break;
		case 2:
			CallScript(player1, 7);
			break;
		case 3:
			player1->checkBag();
			break;

		}
	}

	if (ScriptNumber == 6) {
		//call taxi
		system("CLS");
		cout << "You call a taxi to a street you see the sign for across the road. After seeing a beat up ford focus pull up"<<"\n";
		cout << "with the hampden cabs logo on top. you get in and politely ask to go to whitecraigs in newton mearns. " << "\n";
		cout << "after passing through town, you ponder how a colleage once told you that hampden cabs were associated with the mob" << "\n";
		cout << "'how silly' you think, of course thats absolute rubbish. as if on queue, a group of men bundle out of a van at a red light " << "\n";
		cout << "and quite frankly massacre the driver with an array of automatic weapons. You are visibly shaken to say the least." << "\n";
		cout << "you try to flee the scene, but the men, apparently not too happy on having witnesses, proceed to riddle you around the" << "\n";
		cout << "face and chest area." << "\n" << "game over"<<"\n";
		system("pause");
		exit(0);
	}

	if (ScriptNumber == 7) {
		int choice;
		// start walking through bishopbriggs
		do {
			system("CLS");
			cout << "You feel like calling a taxi would be a waste of valuable funds, and you dont know how far home is from here, so you " << "\n";
			cout << "start walking to find some kind of landmark or bus stop or something. You walk through the maze of streets as the business" << "\n";
			cout << "park turns into a council estate, in what can only be described as an area of lower socio-economic status. Crossing into a " << "\n";
			cout << "nearby park, you see youths drinking tonic wine and playing music from an old sony ericson mobile. One man in a donnay tracksuit" << "\n";
			cout << "who looks like he must be between the ages of 12 and 40, runs at quite a speed towards you. Knowing he means business" << "\n";
			cout << "" << "\n" << "Do you: " << "\n";

			cout << "1: get ready for a scrap and take this cunt on" << "\n";
			cout << "2: attempt to escape to avoid the fight" << "\n";
			cout << "3: check your bag" << "\n";

			cin >> choice;

			switch (choice) {
			case 1:
				CallScript(player1, 9);
				break;
			case 2:
				CallScript(player1, 8);
				break;
			case 3:
				system("CLS");
				player1->checkBag();
				break;

			}
		} while (choice != 1 || choice != 2);

	}

	if (ScriptNumber == 8) 
	{
	
		int choice;
		cout << "You make the snap decision to run and begin sprinting down the side of the park. Over" << "\n";
		cout << "the hill you discover an abandoned looking business park and seeing no other option, " << "\n";
		cout << "you dart into one of the first buildings, and run into a factory room. Running up the" << "\n";
		cout << "stairs you discover about five or six of the gang members are right behind you. You run" << "\n";
		cout << "into the office at the top of the room and slam the door behind you, and drop a large" << "\n";
		cout << "cabinet behind you, blocking the door." << "\n";
		
		PuzzleSystem *puzzle1 = new TextPuzzleRoom(new TextPuzzleSystem(player1, 1), 5);
		puzzle1->CallPuzzleScript(player1, 1);
		//use this to create a puzzle

		cout << "The door code works and just as the door behind you gives in, you slam the door open and" << "\n";
		cout << "feel a thud on the other side followed by a scream. looking out you see that you have " << "\n";
		cout << "knocked the leader of the neds off the top of the stairs, and he looks horrifically injured" << "\n";
		cout << "before you can react the other neds come around and see what has happened. As you prepare for" << "\n";
		cout << "certain death, to your surprise one ned comes and introduces himself." << "\n";

		cout << "Wee Stevie: hawwright mate, that was badass mate whit ye called?" << "\n";
		cout <<player1->getPlayerName()<< ": I beg your pardon?" << "\n";
		cout << "Wee Stevie: Am Stevie, thats tam oe'er there, and were the fuckin fleeto mate" << "\n";
		cout << "you deduce that a fleeto is a gang and they want to know your name"<< "\n";
		cout << player1->getPlayerName() << ": my name is " <<player1->getPlayerName()<<" and im just looking"<<"\n";
		cout <<"to get home, you see I'm just here for the holidays and I'd really like your hel...."<<"\n";
		cout << "just before you can finish, another large gang appears, and from the vibe you are getting," << "\n";
		cout << "you can tell a fight is about to kick off." << "\n";
		cout << "Do you: " << "\n";
		do {
			cin >> choice;

			cout << "1: join this 'fleeto' and fight back your attacker" << "\n";
			cout << "2: cut your losses and run" << endl;
			cout << "3: check your bag " << endl;

			switch (choice)
			{
			case 1:
				CallScript(player1, 10);
				break;
			case 2:
				//death
				exit(0);
				break;
			case 3:
				player1->checkBag();
				break;
			}
		} while (choice != 1 || choice != 2);
	}
	if (ScriptNumber == 9)
	{
		/*you fight the guy from script 7 then after winning his friends are amazed by how great you are and you think you are there leader now
		 you decide to either stab the guy you just beat up to solidify your dominance
		 preach peace and talk your way out of it
		*/
		EnemyEntity* Tony = new BossEnemy("Tony fae the scheme", 10, 3, 1, 5);
		BattleSystem* battle = new BossTextBattleSystem(player1, Tony);
		bool fight = battle->fight(player1, Tony);
		if (fight == false)
		{
			cout << "On the ground, mouth tasting of copper, you regret coming to glasgow" << "\n";
			cout << "The last thing you remember before falling unconscious is audibly shitting " << "\n";
			cout << "yourself. What an absolute embarrassment." << "\n";
			system("pause");
			exit(0);
		}


		delete Tony;
		delete battle;
		CallScript(player1, 11);
		

	}

	if (ScriptNumber == 10)
	{
		/* You fight the bad guys, after stevie gives you his number and texts you quests*/
		int choice;
		cout << "The two groups of youths come to within a few feet of eachother, shouting vile obscenities" << "\n";
		cout << "and threatening extreme violence. You feel like you need to solidify your new found leadership" << "\n";
		cout << "role." << "\n";
		system("pause");
		system("CLS");
		cout << "Wee Stevie: here, "<<player1->getPlayerName()<<" lets do these cunts moan show these wee fannies" << "\n";
		cout << "how we run the scheme" << "\n";
		system("pause");
		system("CLS");
		cout <<player1->getPlayerName()<<": Okidokey, although stevie I would be amiss if I didnt voice my concern"<<"\n";
		cout << "that there appears to be alot more of them than us." << "\n";
		system("pause");
		system("CLS");
		cout << "Wee Stevie: Your right mate, but if you knock out that big cunt oe'r there I bet they'll all shite it" << "\n";
		system("pause");
		system("CLS");
		cout << "Stevie points to a big lad brandishing a baseball bat. This man looks menacing but it's either fight him or " << "\n";
		cout << "fight his associates, or you could possibly talk your way out of it " << "\n";

		do {
			system("CLS");
			cout << "Do you: " << "\n";
			cout << "1: fight the big guy" << "\n";
			cout << "2: fight his mates" << "\n";
			cout << "3: try and bullshit your way out of this mess." << "\n";
			cout << "4: check your bag" << endl;
			cin >> choice;

			switch (choice)
			{
			case 1:
				system("CLS");
				cout << "This is the end of the games demo version, to purchase the full game please wire $40 of bitcoin to EA," << endl;
				cout << "EA sports, it not in the game" << endl;
				system("pause");
				exit(0);
				break;
			case 2:
				system("CLS");
				cout << "This is the end of the games demo version, to purchase the full game please wire $40 of bitcoin to EA," << endl;
				cout << "EA sports, it not in the game" << endl;
				system("pause");
				exit(0);
				break;
			case 3:
				system("CLS");
				cout << "This is the end of the games demo version, to purchase the full game please wire $40 of bitcoin to EA," << endl;
				cout << "EA sports, it not in the game" << endl;
				system("pause");
				exit(0);
				break;
			case 4:
				player1->checkBag();
				break;
			}

		} while (choice != 1 || choice != 2 || choice != 3);



	}
	if (ScriptNumber == 11)
	{
		system("CLS");
		cout << "You have reached the end of the trial verson, please wire $40 worth of Bitcoin for the full version" << endl;
		system("pause");
		exit(0);
	}

	if (ScriptNumber == 12)
	{
		int choice;
		/* you meet barry fae port glesga on the bus, gives you his number and offers a quest*/
		cout << "You run to get on what you believe is the right bus, its heading in the right" << "\n";
		cout << "direction anyway, after a couple minutes at the edge of the city centre, a wiry " << "\n";
		cout << "looking young man comes on and sits beside you. He has an overwhelming aroma of " << "\n";
		cout << "unspecified drugs and just like apparently everyone in this city, decided to strike" << "\n";
		cout << "up a conversation" << "\n";
		cout << "\n";
		system("pause");
		cout << "Barry fae port glesga: Hawwright mate how we doin where are you fae?" << "\n";
		cout << "\n";
		system("pause");
		cout <<player1->getPlayerName()<< ": Well i was born in England but im from a charming little town " << "\n";
		cout << "just south of Edin..." << "\n";
		cout << "\n";
		system("pause");
		cout << "Barry fae port glesga: Wit! haha unbelievable from England and Edinburgh at the same time" << "\n";
		cout << "how have you no been picked aff yet." << "\n";
		cout << "\n";
		system("pause");
		cout << player1->getPlayerName() << ": Excuse me?" << "\n";
		cout << "\n";
		system("pause");
		cout << "Barry fae port glesga: Nevermind mate, here you look like a smart fella wanty help us oot and " << "\n";
		cout << "I'll make it worth yer while?" << "\n";
		cout << "\n";
		system("pause");
		cout << player1->getPlayerName() << ": Well i would usually refuse but I do actually require funds. what did you" << "\n";
		cout << "have in mind?" << "\n";
		cout << "\n";
		system("pause");
		cout << "Barry fae port glesga: Nothin major mate just here gee'z yer number ill text you the details this is my stop, cetch y'efter bud." << "\n";
		cout << "Am barry by the way." << "\n";
		cout << "\n";
		system("pause");
		cout << "Before you can tell Barry your name, he has already left and gotten off of the bus to a place that looks like los Angeles " << "\n";
		cout << "after a 200 year nuclear winter. A few minutes pass, and you recieve a text (You can now check your quests)" << "\n";
		system("pause");
		system("CLS");
		do {
			cout << "Do you: " << "\n";
			cout << "1: Get off the bus, you have no idea where you even are and your pretty sure your on the wrong bus" << "\n";
			cout << "2: Continue on, you never know where you might end up" << "\n";
			cout << "3: Check your bag" << "\n";
			cout << "4: Check your phone" << "\n";

			cin >> choice;

			switch (choice)
			{
			case 1:
				system("CLS");
				cout << "This is the end of the games demo version, to purchase the full game please wire $40 of bitcoin to EA," << endl;
				cout << "EA sports, it not in the game" << endl;
				system("pause");
				exit(0);
				break;
			case 2:
				system("CLS");
				cout << "This is the end of the games demo version, to purchase the full game please wire $40 of bitcoin to EA," << endl;
				cout << "EA sports, it not in the game" << endl;
				system("pause");
				exit(0);
				break;
			case 3:
				player1->checkBag();
				break;
			case 4:
				QuestSystem * quest = new TextQuestWithEnemies(new TextQuestSystem(player1, 1), 5);
				quest->CallQuestScript(player1, 1);
				system("CLS");
				cout << "This is the end of the games demo version, to purchase the full game please wire $40 of bitcoin to EA," << endl;
				cout << "EA sports, it not in the game" << endl;
				system("pause");
				exit(0);
				break;
			}

		} while (choice != 1 || choice != 2 || choice != 4);
	}
}

void GameMap::registerObserver(Observer * observer)
{
	observers.push_back(observer);
}

void GameMap::removeObserver(Observer* observer)
{
	vector<Observer*>::iterator it = find(observers.begin(), observers.end(), observer);
	if (it != observers.end())
	{
		swap(*it, observers.back());
		observers.pop_back();
	}
}

void GameMap::notifyObserver(int newDiff)
{
	for (vector<Observer*>::iterator it = observers.begin(); it < observers.end(); it++)
	{
		(*it)->changeDifficulty(this, newDiff);
	}
}