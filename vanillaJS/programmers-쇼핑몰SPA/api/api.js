const baseUrl =
  "https://uikt6pohhh.execute-api.ap-northeast-2.amazonaws.com/dev";

export async function request(url, options) {
  try {
    const response = await fetch(`${baseUrl}${url}`, options);
    if (response.ok) {
      return response.json();
    }
    throw new Error("API 실패");
  } catch (error) {
    console.log(error);
  }
}
