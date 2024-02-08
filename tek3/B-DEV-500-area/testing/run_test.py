import requests

URL = "http://172.17.0.1:8080"
COOKIE = 'auth-cookie'


def post(endpoint, data, token="", parse=True):
    r = requests.post(f"{URL}/{endpoint}", data, headers={"Authorization": "Bearer " + token})
    print(r.status_code)
    return r.json() if parse else r


def delete(endpoint, token="", parse=True):
    r = requests.delete(f"{URL}/{endpoint}", headers={"Authorization": "Bearer " + token})
    print(r.status_code)
    return r.json() if parse else r


def get(endpoint, token="", parse=True):
    r = requests.get(f"{URL}/{endpoint}", headers={"Authorization": "Bearer " + token})
    print(r.status_code)
    return r.json() if parse else r


print("==TEST REGISTER==")
if get("exist/user_area"):
    print("user already existing")
else:
    print(post("signup", {"username": 'user_area', "password": 'pass_area'}))

print("\n==TEST LOGIN==")
user = post("login", {"username": 'user_area', "password": 'pass_area'})['token']
print(get("user/profile", user))

print("\n==TEST HAS API==")
epitech = get("user/hasApi/epitech", user)
print("has epitech =", epitech)

print("\n==TEST GET ADDACCOUNT==")
print(get("user/epitech/addAccount", user))

print("\n==TEST POST CALLBACK==")
if epitech:
    print("api already existing")
    print(delete("user/deleteApi/epitech", user, False))
print(post("user/epitech/callback", {"user_cookie": COOKIE}, user, False))

print("\n==TEST GET ACTION==")
actions = get("user/getActions", user)
print(actions)

print("\n==TEST GET REACTION==")
reactions = get("user/getReactions", user)
print(reactions)

print("\n==TEST ADD ADDACTIONREACTION==")
print(post("user/addActionReaction", {
    "action_id": actions[0]['_id'],
    "reaction_id": reactions[0]['_id'],
    "action_params": "",
    "reaction_params": "Website:itWorks"
}, user))


print("\n==TEST GET ACTIONREACTION==")
ar = get("user/getActionReaction", user)
print(ar)

print("\n==TEST DELETE ACTIONREACTION==")
print(delete("user/deleteActionReaction/" + ar[0]['_id'], user, False))
