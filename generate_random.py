import requests

def generate_random_numbers(min_value, max_value, count):
    url = f"https://www.random.org/integers/?num={count}&min={min_value}&max={max_value}&col=1&base=10&format=plain&rnd=new"

    response = requests.get(url)
    if response.status_code == 200:
        random_numbers = response.text.strip().split("\n")
        return random_numbers
    else:
        raise Exception("Random number generation failed")

# Example usage


