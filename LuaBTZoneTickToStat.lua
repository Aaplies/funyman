p1,p2,i,t,v,s1,s2,s3 = 100,10000,100000,1000000,10000000,1000000000,100000000000,10000000000000;
io.write(
  [[
  What area are you going to train?
  1 = Ice Bath (100)
  2 = Fire Bath (10K)
  3 = Iceberg (100K)
  4 = Tornado (1M)
  5 = Volcano (10M)
  6 = Hell Fire Pit (1B)
  7 = Green Acid Pool (100B)
  8 = Red Acid Pool (10T)
  ]]
);
area = tonumber(io.read());
if area == 1 then
  req = p1;
elseif area == 2 then
  req = p2;
elseif area == 3 then
  req = i;
elseif area == 4 then
  req = t;
elseif area == 5 then
  req = v;
elseif area == 6 then
  req = s1;
elseif area == 7 then
  req = s2;
elseif area == 8 then
  req = s3;
else
  print('No option for that number. Restart this program.');
end
io.write("How many ticks do you want to survive? 1-79\n");
ticks = tonumber(io.read());
if ticks <= 79 and ticks >= 1 then
  print('You need '..((req/20)*ticks)..' BT for '..ticks..' ticks. If you are unsure about what that number is, use https://www.calculatorsoup.com/calculators/conversions/numberstowords.php to convert it. Never gonna give you up, never gonna let you down.');
else
  print("Stop picking random stuff. Restart this program. Any number past 79 is enough to live forever.");
end
