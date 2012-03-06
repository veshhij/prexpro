class WrongNumberOfPlayersError < StandardError ; end
class NoSuchStrategyError < StandardError ; end

def rps_game_winner(game)
  raise WrongNumberOfPlayersError unless game.length == 2
  g = game[0][1] + game[1][1]
  case g.downcase
  when "rs", "sp", "pr", "rr", "ss", "pp"
    return game[0]
  when "sr", "ps", "rp"
    return game[1]
  else
    raise NoSuchStrategyError
  end
end

def rps_tournament_winner( game )
  if game[0][0].is_a?( String )
    return rps_game_winner( game )
  end
  g = []
  g << rps_tournament_winner( game[0] ) << rps_tournament_winner( game[1] )
  rps_game_winner( g )
end