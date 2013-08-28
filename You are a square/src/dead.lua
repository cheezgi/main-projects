function love.draw()
	love.graphics.setColor(0, 0, 0)
	love.graphics.print("You died. Try again!", 100, 100)
end

function love.mousepressed(x, y, button)
	if button == "l" then
		love.graphics.clear()
		require("game")
	end
end