
print("Pay Check Calculator") #introduction


TAX_RATE = 18

hours_worked = int(input("Hours Worked:")) # hours worked
hourly_rate = float(input("Hourly Pay Rate:")) # hourly pay rate 


gross_pay = hours_worked * hourly_rate

print(F"Gross Pay: {gross_pay:.2f}")

print(f"Tax Rate: {TAX_RATE}%")

tax_amount = gross_pay * (TAX_RATE/100)

print(F"Tax Amount: {tax_amount:.2f}")

take_home_pay = gross_pay - tax_amount

print(F"Take Home Pay: {take_home_pay:.2f}")
