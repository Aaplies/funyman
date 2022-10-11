io.write("How much do you get per tick?(Dont use letters at the end): ")
apt = string.gsub(io.read(),",","")
io.write("How many hours do you want to train for?: ")
hoursTraining = string.gsub(io.read(),",","")
io.write("What stat are you training? PS, FS, or BT. : ")
statTraining = string.lower(io.read())
statTickSpeed = 1
if statTraining == "ps" then
  statTickSpeed = 1.5
elseif statTraining == "bt" then
  statTickSpeed = 1.25
end
print("You will get "..(((apt * 3600) * statTickSpeed ) * hoursTraining).." "..statTraining.." in "..hoursTraining.." hour/s")
