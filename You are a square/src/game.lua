local squareX = 0
local squareY = 0
local score = 0
local startTime = os.time()
local circleX = 100
local circleY = 100
local cSpeed = 100 --speed that the circle is moving at
local sSpeed = cSpeed + 100 -- speed that the square is moving at
local tmpTime = 0
local health = 250
local font = love.graphics.newFont(18)
local square = love.graphics.newImage("sqr.jpg")
local circle = love.graphics.newImage("circle.png")

--dt is the time between the last time called and now
--which stands for delta time
function love.update(dt)
	if love.keyboard.isDown("w") then -- up
		squareY = squareY - sSpeed * dt
	end
	
	if love.keyboard.isDown("s") then -- down
		squareY = squareY + sSpeed * dt
	end
	
	if love.keyboard.isDown("a") then -- left
		squareX = squareX - sSpeed * dt
	end
	
	if love.keyboard.isDown("d") then -- right
		squareX = squareX + sSpeed * dt
	end
	
	--circle AI
	--as of now the circle just follows you around
	if circleX < squareX then
		circleX = circleX + cSpeed * dt
	end
	if circleX > squareX then
		circleX = circleX - cSpeed * dt
	end
	if circleY < squareY then
		circleY = circleY + cSpeed * dt
	end
	if circleY > squareY then
		circleY = circleY - cSpeed * dt
	end
	
	--collision detection
	
	diffX = squareX - circleX
	diffY = squareY - circleY
	
	if (diffX > -20 and diffX < 40) and (diffY > -20 and diffY < 40) then
		health = health - .3
	end
	
	--check health
	if health == 0 or health < 0 then
		require("dead")
	end
	
	--score
	currentTime = os.time()
	score = (currentTime - startTime) + 1
	
end

function love.draw()
	love.graphics.setColor(255, 255, 255) --white
	love.graphics.draw(square, squareX, squareY) --draw square
	love.graphics.draw(circle, circleX, circleY) --draw circle
	
	love.graphics.setColor(0, 0, 0) --black
	love.graphics.print("Score: "..score, 0, 0)
	love.graphics.print("Health", 355, 0)
	
	red = 65
	blue = 105
	green = 225
	
	if health <= 100 then
		red = 255
		blue = 251
		green = 0
	end
	if health <= 25 then
		red = 255
		blue = 46
		green = 36
	end
	
	love.graphics.setColor(red, blue, green) --royal blue (my favorite color)
	love.graphics.rectangle("fill", 100, 3, health, 15) --health meter
	
	love.graphics.setColor(0, 0, 0)
	love.graphics.rectangle("line", 99, 2, 252, 17)
	
	--debugging
	-- love.graphics.setColor(0, 0, 0) --black
	-- love.graphics.print("squareX = "..squareX..", squareY = "..squareY, 0, 50)
	-- love.graphics.print("circleX = "..circleX..", circleY = "..circleY, 0, 100)
	-- love.graphics.print("diffX = "..diffX..", diffY = "..diffY, 0, 150)
	-- love.graphics.print("health = "..health, 0, 200)
	-- love.graphics.print("currentTime = "..currentTime, 0, 250)
	-- love.graphics.print("red = "..red, 0, 300)
end






















