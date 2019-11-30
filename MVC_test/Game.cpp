//
//  Game.cpp
//  MVC_test
//
//  Created by 김노은 on 30/11/2019.
//  Copyright © 2019 Noeun-Kim. All rights reserved.
//

#include <stdio.h>
#include <map>

#include "Player.h"
#include "Hand.h"
#include "Deck.h"
#include "Evaluator.cpp"

using namespace std;

class Game {
private:
    map<string, Player> playerList;
    Deck deck;
    
public:
    Game() {}
    Game(Deck &newDeck) {
        deck = newDeck;
    }
    
    // Getter
    map<string, Player> getPlayerList() {
        return this->playerList;
    }
    int getNumOfPlayerList() {
        cout << this->playerList.size() <<endl;
        return this->playerList.size();
    }
    
    // 공개 함수
    void addPlayer(string playerName, int seedMoney) {
        Hand hand = *new Hand(this->deck);
        Player player = *new Player(seedMoney, hand);
        if (this->playerList.find(playerName) == this->playerList.end()) {
            this->playerList.insert(std::pair<string, Player>(playerName, player));
             cout << "addPlayer" <<endl;
        } else {
            cout << "DuplicatePlayerException" <<endl;
            // throw new DuplicatePlayerException();
        }
    }
    
    void placeBet(string name, int bet) {
        Player player;
        if (this->playerList.find(name) == this->playerList.end()) {
            cout << "PlayerDoesNotExistException" <<endl;
            // throw new PlayerDoesNotExistException();
        } else {
            player = this->playerList[name];
            player.placeBet(bet);
            cout << "placeBet" <<endl;
        }
    }
    
    void start() {
        std::map<string, Player>::iterator it;
        
        int playerNumber;
        int betMoney;
        int initMoney;
        string pyrName;
        
        Player player;
        
        cout << "! 게임 인원을 설정하세요: ";
        cin >> playerNumber;
        cout << "! 정원이 " << playerNumber << " 명으로 설정되었습니다." << endl;
        
        cout << "! 게임 참여자 설정을 시작합니다." << endl;
        
        for (int i = 0; i < playerNumber; i++){
            cout << "!! " <<  i+1 << "번 참가자의 이름을 입력하세요: ";
            cin >> pyrName;
            cout << "!! " <<  i+1 << "번 참가자의 초기 자본을 입력하세요: ";
            cin >> initMoney;
            addPlayer(pyrName, initMoney);
        }
        cout << "! 게임 참여자 설정이 완료되었습니다." << endl << endl;
        cout << "! 베팅을 시작합니다." << endl;
        for (it=playerList.begin(); it!=playerList.end(); ++it){
            pyrName = it->first;
            cout << "!! '" << pyrName << "'의 베팅 금액을 입력하세요: ";
            cin >> betMoney;
            player = playerList[it->first];
            player.placeBet(betMoney);
        }
        cout << endl;
        
        Evaluator evaluator = *new Evaluator(this->playerList);
        evaluator.start();
    }
};
