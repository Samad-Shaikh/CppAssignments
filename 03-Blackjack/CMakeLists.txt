cmake_minimum_required(VERSION 3.17)
project(Blackjack)

set(CMAKE_CXX_STANDARD 14)


#vectors bound check
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -D_GLIBCXX_DEBUG")

add_executable(Blackjack main.cpp Card.cpp Card.h Deck.cpp Deck.h Blackjack.cpp Blackjack.h Game.cpp Game.h)